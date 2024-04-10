#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define mod 1000000007
#define maxn 400400

using namespace std;

int T[maxn];

int sum(int idx){
    int ret = 0;
    idx++;
     while(idx){
                ret += T[idx];
                ret %= mod;
                idx -= (idx&-idx);}
     return ret;}
     
void update(int idx,long long val){
	  idx++;
      while(idx < maxn){
                T[idx] += val;
                T[idx] %= mod;
                idx += (idx&-idx);
      }
}

int ans[500500];

struct query {
	int t,k,sig,idx;
	query(int t=0,int k=0,int sig=0,int idx=0): t(t), k(k), sig(sig), idx(idx) {}
	bool operator<(query comp) const{
		return t < comp.t;
	}
};

int n;
int log2u = 0;
int str[maxn];
int sarray[maxn];
int pos[maxn];
int rev[maxn];
int index2[20][maxn];

bool comp(int a,int b){
     
     if(log2u == 0)
          return str[a] < str[b];
          
     
     if(index2[log2u][a] != index2[log2u][b])
                 return index2[log2u][a] < index2[log2u][b];
                 
     a = min(n,a+(1<<(log2u-1)));
     b = min(n,b+(1<<(log2u-1)));
     
     return index2[log2u][a] < index2[log2u][b];
}

int rmq[20][maxn];
int LG[maxn];
int LCP[maxn];

int lcp2(int a,int b){

	debug("lcp2 %d %d",a,b);
	//a = sarray[a];
	//b = sarray[b];  
    if(a>b)swap(a,b);

	if(a == b) return n-a;
	b--;
	
	int len = b-a+1;

	debug(" (min %d %d %d) ",rmq[LG[len]][a],rmq[LG[len]][b+1-(1<<LG[len])],len);
	int ret = min(rmq[LG[len]][a],rmq[LG[len]][b+1-(1<<LG[len])]);
	if(a == b)ret = LCP[a];
	debug(" = %d\n",ret);
	return ret;

}	

int lcp(int a,int b){

	debug("lcp %d %d",a,b);
	a = sarray[a];
	b = sarray[b];
    if(a<b)swap(a,b);
    
    if(a == b)return n-a;
    
    int ret = 0;
    
    for(int i=log2u; i>0; i--){
            
            if(index2[i][a+ret] == index2[i][b+ret]){
                                ret += (1<<(i-1));
                                if(a+ret >= n)return n-a;
                                }
            
            }   

    debug(" = %d\n",ret);
    return ret;
}

int len[maxn];
int l[maxn];
int r[maxn];

char tmp[maxn];

main(){

		LG[1] = LG[2] = 0;

		for(int i=3;i<maxn;i++){
			LG[i] = LG[i-1];
			if((i-1) == ((i-1)&-(i-1))) LG[i]++;
		}

		int N,q;
		n = 0;
		scanf("%d%d",&N,&q);

		int cur = 200;

		for(int i=0;i<N;i++){

			scanf(" %s",tmp);
			len[i] = strlen(tmp);
			for(int j=0;j<len[i];j++)
				str[n++] = tmp[j];

			str[n++] = cur++;

			if(i == 0){
				l[i] = 0;
				r[i] = len[i]-1;
			}
			else{
				l[i] = 2 + r[i-1];
				r[i] = l[i]+len[i]-1;
			}

		}

		for(int i=0;i<n;i++)
               sarray[i] = i;
       
       int d = 0;
       log2u = 0;
       
       for(int i=0;i<20;i++)
               index2[i][n] = -1;


       
       while(d < n-1){
               
               sort(sarray,sarray+n,comp);
               
               index2[log2u+1][sarray[0]] = 0;
               
               for(int i=1;i<n;i++)
                       index2[log2u+1][sarray[i]] = index2[log2u+1][sarray[i-1]] + (comp(sarray[i-1],sarray[i])?1:0);
                       
               d = index2[log2u+1][sarray[n-1]];
               log2u++;
       }



        for(int i=0;i<n;i++)
       		rev[sarray[i]] = i;

       	for(int i=0;i<n-1;i++){
       		 LCP[i] = lcp(i,i+1);
       		 debug("LCP %d %d = %d\n",i,i+1,LCP[i]);
        }

       	for(int i=0;i<n-1;i++)
				rmq[0][i] = LCP[i];

		for(int i=1;i<20;i++)
			for(int j=0;j<n-1;j++)
				rmq[i][j] = min(rmq[i-1][j],rmq[i-1][min(n-2,j+(1<<(i-1)))]);
		

    	vector<query> Q;

    	for(int i=0;i<q;i++){

    		int l,r,k;
    		scanf("%d%d%d",&l,&r,&k), l--, r--, k--;

    		Q.pb(query(r,k,1,i));
    		if(l) Q.pb(query(l-1,k,-1,i));

    	}

    	sort(Q.begin(), Q.end());

    	int ligou = -1;

    	for(int i=0;i<Q.size();i++){
    		while(ligou < Q[i].t){

				ligou++;
    			for(int j=l[ligou];j<=r[ligou];j++){
    				update(rev[j],1);
    			}

    		}


			int cara = rev[l[Q[i].k]];
			int tam = r[Q[i].k] - l[Q[i].k] + 1;

    		int low = 0, up = cara;

    		while(low != up){

    			int mid = (low+up)/2;

    			if(lcp2(mid,cara) >= tam)
    				up = mid;
    			else
    				low = mid+1;

    		}

    		int A = low;

    		low = cara, up = n-1;

    		while(low != up){

    			int mid = (low+up+1)/2;
    			if(lcp2(mid,cara) >= tam)
    				low = mid;
    			else
    				up = mid-1;

    		}

    		int B = low;

    		ans[Q[i].idx] += Q[i].sig * (sum(B) - sum(A-1));

    	}

    	for(int i=0;i<q;i++)
    		printf("%d\n",ans[i]);

 }