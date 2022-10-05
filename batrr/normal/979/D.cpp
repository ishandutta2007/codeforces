// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e6+123,inf=1e8,mod=1e9+7,block=200,N=5000+123;
struct vertex{
	int next[2],mn;
};
vertex empty;
vector < vertex > t[maxn];
int q;
void add(int p,int k){
	int v=0;
	for(int i=20;i>=0;i--){
	//	cout<<v<<" ";
		int c=( ( (1<<i)&p ) !=0 );
		if(t[k][v].next[c]==0){
			t[k][v].next[c]=t[k].size();
			t[k].pb(empty);
		}
		v=t[k][v].next[c];          
		t[k][v].mn=min(t[k][v].mn,p);
		//cout<<v<<" ";
	}
}                          
int get(int x,int s,int k){
	int res=0,v=0;
	for(int i=20;i>=0;i--){
		if( (1<<i) & x ){
			if( t[k][ t[k][v].next[0] ].mn<=s )                              
				v=t[k][v].next[0];
			else
				v=t[k][v].next[1];
		}else{
			if( t[k][ t[k][v].next[1] ].mn<=s )                              
				v=t[k][v].next[1];
			else
				v=t[k][v].next[0];
		}              
		if(v==0 || t[k][v].mn>s)
			return -1;
	}
	return t[k][v].mn;	
}                            
int main(){
    #ifdef LOCAL
		freopen ("test.in", "r", stdin);
	#endif                                
	cin>>q;         
	empty.next[0]=0;
	empty.next[1]=0;
	empty.mn=1e9;
	for(int i=0;i<maxn;i++)
		t[i].pb(empty);  
	while(q--){
		int type,x,k,v,s;
		cin>>type;
		if(type==1){
			cin>>v;
			for(int i=1;i*i<=v;i++){
				if(v%i==0){
					add(v,i);
					add(v,v/i);
				}
			}
		}else{
			cin>>x>>k>>s;
			if(x%k!=0)
				cout<<-1<<endl;
			else
				cout<<get(x,s-x,k)<<endl;
		}
	}
}