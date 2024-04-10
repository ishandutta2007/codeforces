#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
	int x,y;
	Point(int _x=0,int _y=0):x(_x),y(_y){};
}a[3];
inline ll Dis(Point a,Point b){
	return (ll)abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> X,Y;
	for(int i=0;i<3;++i){
		cin>>a[i].x>>a[i].y;
		X.push_back(a[i].x);
		Y.push_back(a[i].y);
	}
	ll len=1e18;
	vector<pair<Point,Point> > ans;
	for(auto x:X){
		for(auto y:Y){
			ll tmp=0;
			for(int i=0;i<3;++i){
				tmp+=Dis(Point(x,y),a[i]);
			}
			if(tmp<len){
				len=tmp;
				ans.clear();
				for(int i=0;i<3;++i){
					ans.emplace_back(Point(a[i].x,a[i].y),Point(a[i].x,y));
					ans.emplace_back(Point(a[i].x,y),Point(x,y));
				}
			}
		}
	}
	vector<pair<Point,Point> > zz;
	for(auto [a,b]:ans){
		if(a.x==b.x&&a.y==b.y)continue;
		zz.emplace_back(a,b);
	}
	cout<<zz.size()<<'\n';
	for(auto [a,b]:zz){
		cout<<a.x<<' '<<a.y<<' '<<b.x<<' '<<b.y<<'\n';
	}
	return 0;
}