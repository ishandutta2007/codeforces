#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int flag;
vector<pair<char,int> > x,y;
vector<pair<int,int> > ans;
vector<pair<char,int> > init(string s) {
	vector<pair<char,int> > v;
	for (int i=0,j=0;i<s.size();i=j+1) {
		while (j<s.size()-1&&s[j+1]==s[i]) j++;
		v.push_back(make_pair(s[i],j-i+1));
	}
	reverse(v.begin(),v.end());
	return v;
}
int len(vector<pair<char,int> > v) {
	int res=0;
	for (int i=0;i<v.size();i++)
		res+=v[i].second;
	return res;
}
vector<pair<char,int> > f(vector<pair<char,int> > &v,int a) {
	vector<pair<char,int> > res;
	while (a--) {
		res.push_back(v.back());
		v.pop_back();
	}
	reverse(res.begin(),res.end());
	return res;
}
void add(vector<pair<char,int> > &v,vector<pair<char,int> > d) {
	pair<char,int> tmp;
	for (int i=0;i<d.size();i++) {
		tmp=d[i];
		if (tmp.first==v.back().first)
			v[v.size()-1].second+=tmp.second;
		else v.push_back(tmp);
	}
}
void change(int a,int b) {
	vector<pair<char,int> > gx=f(x,a),gy=f(y,b);
	int lx=len(gx),ly=len(gy);
	if (flag) swap(lx,ly);
	ans.push_back(make_pair(lx,ly));
	add(x,gy); add(y,gx);
}
int main() {
	//freopen("1.txt","r",stdin);
	string s,t;
	cin>>s>>t;
	x=init(s),y=init(t);
	int a,b;
	while (1) {
		if (x.size()==1&&y.size()==1) break;
		if (x.size()<y.size()) {
			swap(x,y); flag^=1;
		}
		a=x.size(); b=y.size();
		if (x.back().first!=y.back().first) {
			if (b<=2) {
				if (a<=3) change(1,1);
				else change(3,1);
			} else change(1,1);
		} else {
			if (b==1) {
				if (a<=3) change(1,0);
				else change(3,0);
			} else if (b==2) {
				if (a==2) change(1,0);
				else change(2,1);
			} else change(3,2);
		}
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}