#include<bits/stdc++.h>
using namespace std;
enum{N=200009};
int a[N],p[N],e[N],u[N],b[N],to[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,n,rt,v,t,bg,las,tmp;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)p[i]=0; 
		for(i=1;i<=n;++i){
			cin>>a[i];
			if(!p[a[i]])p[a[i]]=i;
			else e[i]=p[a[i]],e[p[a[i]]]=i,p[a[i]]=0;
		} 
		rt=0;
		for(i=1;i<=n;++i){to[i]=0;
			if(p[i]){
				if(rt){
					cout<<"NO\n";
					goto gg;
				}
				rt=p[i];
				e[rt]=0;
			}
		}
		if((n&1)&&rt==n/2+1){
			for(i=1;i<=n;++i)p[i]=0;
			for(i=n;i;--i){
				if(!p[a[i]])p[a[i]]=i;
				else e[i]=p[a[i]],e[p[a[i]]]=i,p[a[i]]=0;
			}
				rt=0;
			for(i=1;i<=n;++i){to[i]=0;
				if(p[i]){
					rt=p[i];
				e[rt]=0;
				}
			}
			if(rt==n/2+1){
				cout<<"NO\n";
				goto gg;}
		}
	/*	v=0;
		for(i=1;i<=n/2;++i)if(e[i]==n+1-i){
			u[++v]=i;
		}
		for(i=1;i<v;++i)to[u[i]]=u[i+1];
		to[u[v]]=n+1-u[1];
		for(i=1;i<v;++i)to[n+1-u[i]]=n+1-u[i+1];
		to[n+1-u[v]]=u[1];
		if(n&1)j=n/2+1,to[j]=rt;
		else{
			j=0;
			for(i=1;i<=n;++i)if(!to[i]){j=i;break;}
			if(!j)goto g2;
		}
		bg=j;
		t=0;
		do{
			b[++t]=j;
			if(to[j])j=to[j];
			else{
				to[j]=n+1-j;
				j=to[j];
				b[++t]=j;
				to[j]=e[j];
				j=to[j];
			}
		}while(j!=bg);
		las=b[t-1];
		for(i=1;i<=n;++i)if(!to[i]){
			t=0;j=i;
			do{
			b[++t]=j;
			if(to[j])j=to[j];
			else{
				to[j]=n+1-j;
				j=to[j];
				b[++t]=j;
				to[j]=e[j];
				j=to[j];
			}
			}while(j!=i);
			to[las]=b[1];
			to[b[t-1]]=n+1-las;
			to[n+1-las]=b[t];
			to[b[t]]=bg;
			las=n+1-las;
			//las=b[t-1];
		}
		for(i=1;i<=n;++i)cout<<to[i]<<'!';*/
		/*10 4 8 1 6 5 2 7 3 9
		1->10 10->9 9->3 3->8 8->7 7->2 2->4 4->1
		2->4 4->1 6->5 5->6 2->5 5->4 4->
		6->5 5->6
		1->2 2->1 3->4 4->3  1->3 3->2 2->4 4->1 5->6 6->5
		* 1->3 3->5 5->2 2->4 4->6 6->1
		* 
		* 5->1 to[b[t-1]]=bg to[b[t]]=e[bg]*/
		//for(i=1;i<=t;++i)cout<<b[i]<<'!';
	/*	cout<<las<<'?';
		if(v){
		to[las]=u[1];
		to[u[v]]=n+1-las;
		to[n+1-las]=n+1-u[1];
		to[n+1-u[v]]=bg;
	}
		g2:;
		cout<<"YES\n";
		for(i=1;i<=n;++i)cout<<to[i]<<' ';cout<<'\n';*/
		if(n&1)j=n/2+1,to[j]=rt;
		else j=1;
		bg=j;
		t=0;
		do{
			b[++t]=j;
			if(to[j])j=to[j];
			else{
				to[j]=n+1-j;
				j=to[j];
				b[++t]=j;
				to[j]=e[j];
				j=to[j];
			}
		}while(j!=bg);
		las=b[t-1];
		for(i=1;i<=n;++i)if(!to[i]){
			//for(j=1;j<=n;++j)cout<<to[j]<<' ';cout<<'!'<<'\n';
			t=0,j=i;
			do{
			b[++t]=j;
				to[j]=n+1-j;
				j=to[j];
				b[++t]=j;
				to[j]=e[j];
				j=to[j];
		}while(j!=i);
		tmp=to[las];
		to[las]=b[1];to[b[t-1]]=tmp;
		tmp=to[n+1-las];
		to[n+1-las]=b[t];to[b[t]]=tmp;
		}
		cout<<"YES\n";
		for(i=1;i<=n;++i)cout<<to[i]<<' ';cout<<'\n';
		gg:;
	}
}/*
1
10
1 1 2 2 3 3 4 4 5 5
* 1->10 10->9 9->2 2->1
* 3->8 8->7 7->4 4->3
* 5->6 6->5
* 1->10 10->9 9->3 3->8 8->7 7->2 2->4 4->1
* 9->5 5->3 3->8 8->7 7->2 2->6 6->4 4->1

1
9
1 1 2 3 3 2 4 5 5
1 2 3 3 1
5->7 7->3 3->6 6->4 4->5
1->9 9->8 8->2 2->1
6->1 1->9 9->8 8->4 4->2 2->5

1->5 5->1
3->2 2->4 4->3
3->2 2->1 1->4 4->5 5->3
1 1 2 3 3 2 4 4
3->4 4->6 6->5 5->3
1->8 8->7 7->2 2->1
1->8 8->7 7->3 3->4 4->2 2->6 6->5 5->1
1 1 2 2 3 3
3->4 4->3
1->6 6->5 5->2 2->1
1->6
6->5
5->3
3->2
2->4
4->1*/