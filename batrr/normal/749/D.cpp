#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <cstdio>    
#define pb push_back
#define f first
#define s second	
#define mp make_pair
using namespace std;
const int maxn=2e5+10;
int n,m,k,amx[maxn],c;
set< pair<int,int > >b;
pair<int,int>nn;
vector<int>d[maxn];         
int main () { 
    scanf("%d", &n);
    for(int i = 0;i < n; i++){    
        scanf("%d%d", &nn.f,&nn.s);
    	d[nn.f].pb(nn.s);
    	amx[nn.f]=nn.s;
    }
    for(int i = 1;i <= n; i++)
    	if(amx[i]!=0)
    		b.insert(mp(-amx[i],i));
    scanf("%d", &m);
    while(m--){
		vector<pair<int,int> >a;
    	scanf("%d", &k);       
        for(int i=0;i<k;i++){
   			scanf("%d", &c);
  	    	b.erase(mp(-amx[c],c));
  	    	if(amx[c]!=0)
  	    		a.pb(mp(-amx[c],c));		
   		}                          
    	if(b.empty()){
    		printf("%d %d\n",0,0);
        }else if(b.size()==1){
    		printf("%d %d\n", (*b.begin()).s,d[(*b.begin()).s][0]);
    	}else{
			set< pair<int,int > > :: iterator it=b.begin();
			it++;
			int mx=-(*it).f,e=(*b.begin()).s;
			int l=0,r=d[e].size()-1;			
			while(l<=r){
				int m=(l+r)/2;
				if(d[e][m]<=mx)
					l=m+1;
				else
					r=m-1;	
			}
			printf("%d %d\n", e,d[e][l]);  		
   		}
   		for(int i=0;i<a.size();i++)
   			b.insert(a[i]);                
    }
   	return 0;
}