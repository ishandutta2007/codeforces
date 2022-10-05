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
const ll maxn=2123,inf=1e8,mod=1e9+7,block=200,N=1e5+123;
bool used[maxn][10][10][10][10][10];
struct vertex{
	short int i,dis;
	char j,a,b,c,d;
};
int n,st[maxn],en[maxn];
bool check(vertex v){
	if(v.i==-1)
		return 0;
	if(used[v.i][v.j][v.a][v.b][v.c][v.d])
		return 0;
	if(v.i==n+1 && v.a==0 && v.b==0 && v.c==0 && v.d==0){
		cout<<v.dis;
		exit(0);
	}
	used[v.i][v.j][v.a][v.b][v.c][v.d]=1;
	return 1;	
}
vertex get(vertex u){
	if(u.a==u.j)
		u.a=0;
	if(u.b==u.j)
		u.b=0;
	if(u.c==u.j)
		u.c=0;
	if(u.d==u.j)
		u.d=0;
	while(u.i<=n && st[u.i]==u.j){
		if(u.a==0)
			u.a=en[u.i];
		else

		if(u.b==0)
			u.b=en[u.i];
		else

		if(u.c==0)
			u.c=en[u.i];
		else

		if(u.d==0)
			u.d=en[u.i];
		else
			break;
		u.i++;
	}
	return u;
}                  

vertex get1(vertex v){
	vertex u=v;
	u.j--;
	if(u.j==0){
		u.i=-1;
		return u;
	}             
	u.dis++;  
    return get(u);
}             
vertex get2(vertex v){
	vertex u=v;      
	u.j++;
	if(u.j==10){
		u.i=-1;
		return u;
	}             
	u.dis++;  
    return get(u);
}             
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif
	scanf("%d",&n);     
	for(int i=1;i<=n;i++)
		scanf("%d%d",&st[i],&en[i]);
	/*
	for(int i=1;i<=n;i++)
		for(int j=1;j<10;j++)
			for(int a=0;a<10;a++)
				for(int b=0;b<10;b++)
					for(int c=0;c<10;c++)
						for(int d=0;d<10;d++)
							dp[i][j][a][b][c][d]=30000;
	*/
	vertex st;
	st.i=1;
	st.j=1;
	st.a=0;
	st.b=0;
	st.c=0;
	st.d=0;
	st.dis=2*n;
	queue < vertex > q;
	q.push(get(st));
	while(true){
		vertex v=q.front();
		q.pop();
		
		if(check( get1(v) ) ){
			q.push(get1(v));
		}

		if(check( get2(v) ) ){
			q.push(get2(v));
		}

	}
}