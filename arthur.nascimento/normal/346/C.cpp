#include <iostream>
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
 
#define INF (1<<30)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define eps 1e-9
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif
 
using namespace std;

int v[100100];
int z[100100];


int m[1010000];
//int next[13010000];

//int last[1001000];

int ans[1001000];

int card[1001000];

int array[13001000];



struct pt {
	int v,idx;
	pt(int v=0,int idx=0):v(v),idx(idx){}
	bool operator<(pt comp)const{
		return m[v] > m[comp.v];}
};

main(){

		int a,b,N;
		scanf("%d",&N);

		for(int i=0;i<N;i++)
			scanf("%d",z+i);
			
		sort(z,z+N);

		int n=1;
		v[0] = z[0];

		for(int i=1;i<N;i++)
			if(z[i] != z[i-1])
				v[n++] = z[i];


		scanf("%d%d",&a,&b);
		debug("%d %d\n",a,b);
		int cont = 0,c2=0;
		int vsize = 0;

	//	for(int i=0;i<=a-b;i++)
		//	last[i] = i; // !!!!!
		//int qnt = a-b+1;

		for(int i=0;i<n;i++)
			for(int j=(b-(b%v[i])<b) ?b-(b%v[i])+v[i] :b-(b%v[i]) ;j<=a;j+=v[i]){

			//	if(j < b)
				//	continue;
			//	debug("+%d\n",j);
		//		M[j-b].push_back(i);
		//		L[i].push_back(j-b);
				//m[last[j-b]] = i; // j-b
			//	next[last[j-b]] = qnt;
			//	last[j-b] = qnt;
				//y[vsize++] = qnt;
				//qnt++;

				m[j-b] = max(m[j-b], v[i]);
				
			
			}
	//	for(int i=0;i<=a-b;i++)
	//		debug("%d ",m[i]);
	//		for(int p=i;p!=last[i];p=next[p])
	//			cont++;
			
		//sort(y,y+vsize);
		debug("%d %d %d\n",cont,c2,clock());
	//	multiset<int> S;
	//	priority_queue<int> Q;
		int ptr = b;
		int size = 0;
		int cnt3=0;

		priority_queue<pt> Q;

		//for(int i=0;i<n;i++)
			//if(last[i] != i)
				//Q.push(pt(i,i));

		for(int i=b;i<=a;i++){

		//	debug("%d\n",i);

	/*		for(vector<int> :: iterator it = m[i-b].begin(); it < m[i-b].end(); it++){
					if(S.find(i-v[*it]) != S.end())
						S.erase(S.find(i-v[*it]));
					S.insert(i);
				}*/


/*			for(int p = i-b; p != last[i-b]; p = next[p]){
					if(S.find(i-v[m[p]]) != S.end())
						S.erase(S.find(i-v[m[p]]));
					S.insert(i);
			}*/

		/*	for(int p = i-b; p != last[i-b]; p = next[p]){

				///	debug("dec %d i=%d\n",i-v[m[p]],i);
					if(i-v[m[p]] >= b)					
						card[i-v[m[p]]-b]--;
					card[i-b]++;
					//Q.push(-i);
					array[size++] = i;
					
			}*/
			if(m[i-b])
				array[size++] = i;

			/*while(Q.size() && m[Q.top().v] == i){

				int k = Q.top().v;
				int idx = Q.top().idx;
				Q.pop();
			//	debug(": %d dec %d\n",m[k],i-v[idx]);

				if(next[k] != last[idx])
					Q.push(pt(next[k],idx)),
					cnt3++;

				card[i-b]++;
				array[size++] = i;

				if(i-v[m[k]] >= b)
					card[i-v[idx]-b]--;


			}*/

			

		//	for(vector<int> :: iterator it = M[i-b].begin(); it < M[i-b].end(); it++){
		/*	for(int j=0;j<M[i-b].size();j++){
					if(i-v[M[i-b][j]] >= b)
						card[i-v[M[i-b][j]]-b]--;
					card[i-b]++;
					array[size++] = i;
				//	debug("add %d\ntira %d\n",i,i-v[*it]);
				}*/
			

			//for(multiset<int> :: iterator it=S.begin();it!=S.end();it++)
			//	debug("%d ",*it);
			//debug("\n");

		/*	int k = -1;

			while(k == -1 && Q.size()){

				int q = Q.top();
				if(card[-q-b])
					k = -q;
				else
					Q.pop();
				}*/

			while(ptr < i && ptr+m[ptr-b] <= i)
				ptr++;
				
			//debug("ok\n");
			int k = ptr;
			//if(ptr == size)
			//	k = -1;
			debug("k = %d size = %d m = %d ptr = %d\n",k,size,m[i-b],ptr);
				
			//if(S.empty() || *(S.begin()) == i)
			  if(k == -1 ||  k == i)
				ans[i-b] = ans[i-1-b] + 1;

			else
				ans[i-b] = 1 + ans[k-b];

			if(i == b)
				ans[i-b] = 0;

		debug("-> %d %d\n",i,ans[i-b]);
		
		}


		printf("%d\n",ans[a-b]);

	}