#include<bits/stdc++.h>
using namespace std;
 
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int	xy,xq,py,pq,w=1e9,l,r,m,o,x,y,p,q;
	cout<<"? "<<1<<' '<<1<<endl;
	cin>>xy;xy+=2;
	cout<<"? "<<1<<' '<<w<<endl;
	cin>>xq;xq+=1-w;
	cout<<"? "<<w<<' '<<1<<endl;
	cin>>py;py+=1-w;
	pq=xy-xq-py;
	if(xy<=1+w){
		l=1,r=xy-1;
		while(l<=r){
			m=l+r>>1;
			cout<<"? "<<1<<' '<<m<<endl;
			cin>>o;
			if(o==xy-1-m)x=m,l=m+1;
			else r=m-1;
		}
		y=x;
		x=xy-y;
		p=-(py-y);
		q=-(xq-x);
		cout<<"! "<<x<<' '<<y<<' '<<p<<' '<<q<<endl;
	}else{
		l=1,r=(w+1)+(w+1)-pq-1;
		while(l<=r){
			m=l+r>>1;
			cout<<"? "<<w<<' '<<(w+1)-m<<endl;
			cin>>o;
			if(o==((w+1)+(w+1)-pq)-1-m)x=m,l=m+1;
			else r=m-1;
		}
		q=(w+1)-x;
		p=pq-q;
		x=xq+q;
		y=py+p;
		cout<<"! "<<x<<' '<<y<<' '<<p<<' '<<q<<endl;
	}
	return 0;
}