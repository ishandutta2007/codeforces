#include<bits/stdc++.h>

using namespace std;

#define Swapre(x,y) _Swapre(a,b,ans,x,y)
#define pii pair<int,int>
#define fir first
#define sec second

const int L=200000+10;

char s[L],t[L];
int lens,lent;

vector<pii> ans,ans2;
vector<int> a,b;

void _Swapre(vector<int>& a,vector<int>& b,vector<pii>& ans,int x,int y){
	if(a.empty())
		a.emplace_back(0);
	if(b.empty())
		b.emplace_back(0);
	vector<int> c,d;
	for(int i=0;i<x;++i){
		c.emplace_back(a.back());
		a.pop_back();
	}
	for(int i=0;i<y;++i){
		d.emplace_back(b.back());
		b.pop_back();
	}
	int la=a.back(),lb=b.back();
	ans.push_back({la,lb});
	a.pop_back();
	b.pop_back();
	swap(a,b);
	while(!c.empty()){
		a.emplace_back(c.back()-la+lb);
		c.pop_back();
	}
	while(!d.empty()){
		b.emplace_back(d.back()-lb+la);
		d.pop_back();
	}
}

void print(const vector<int> a){
	cout<<"Vector: ";
	for(int i:a)
		cout<<i<<" ";
	cout<<endl;
}

void Solve(vector<pii>& ans){
	for(int i=0;i<lens;++i)
		if(s[i]!=s[i+1])
			a.emplace_back(i+1);
	for(int i=0;i<lent;++i)
		if(t[i]!=t[i+1])
			b.emplace_back(i+1);
	for(;;){
		if((a.size()>1&&b.size()>1)||((a.size()||b.size())&&a.size()<3&&b.size()<3))
			Swapre(0,0);
		else if(a.size()>2)
			Swapre(2,0);
		else if(b.size()>2)
			Swapre(0,2);
		else
			break;
	}
}

int main(){
	cin>>s>>t;
	lens=strlen(s);
	lent=strlen(t);
	s[lens]='a';
	t[lent]='b';
	Solve(ans);
	s[lens]='b';
	t[lent]='a';
	Solve(ans2);
	if(ans2.size()<ans.size())
		ans=ans2;
	cout<<(int)ans.size()<<endl;
	for(pii p:ans)
		cout<<p.fir<<" "<<p.sec<<endl;
}