#include<cstdio>
#include<set>
#include<queue>
using namespace std;
struct seg{
	int a;
	int b;
	seg(){}
	seg(int _a,int _b):a(_a),b(_b){}
	bool operator<(seg rhs)const{return b-a<rhs.b-rhs.a;}
};
int main(){
	int w,h,n,k,mx,my;
	seg tmp;
	char op[5];
	set<int> x,y;
	set<int>::iterator now,pre,nxt;
	priority_queue<seg> qx,qy;
	scanf("%d%d%d",&w,&h,&n);
	x.insert(0);
	x.insert(w);
	y.insert(0);
	y.insert(h);
	qx.push(seg(0,w));
	qy.push(seg(0,h));
	while(n--){
		scanf("%s%d",op,&k);
		if(op[0]=='V') now=x.insert(k).first;
		else now=y.insert(k).first;
		nxt=pre=now;
		nxt++;
		pre--;
		if(op[0]=='V') qx.push(seg(*pre,*now)),qx.push(seg(*now,*nxt));
		else qy.push(seg(*pre,*now)),qy.push(seg(*now,*nxt));
		while(1){
			tmp=qx.top();
			now=x.find(tmp.a);
			++now;
			if(now==x.find(tmp.b)){
				mx=tmp.b-tmp.a;
				break;
			}
			else qx.pop();
		}
		while(1){
			tmp=qy.top();
			now=y.find(tmp.a);
			++now;
			if(now==y.find(tmp.b)){
				my=tmp.b-tmp.a;
				break;
			}
			else qy.pop();
		}
		printf("%I64d\n",1LL*mx*my);
	}
	return 0;
}