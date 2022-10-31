#include<bits/stdc++.h>
#define N 200100
long long a[N];
using namespace std;
struct cmp {
    bool operator()(const long long& x,const long long& y) const {
        return __builtin_popcountll(x)>__builtin_popcountll(y) || __builtin_popcountll(x)==__builtin_popcountll(y)&&x>y;
    }
};
int main(){
	srand (time(NULL));
	int n,m,p;
	char s[100];
	vector<long long> key;
	vector<int> val;
	scanf("%d%d%d",&n,&m,&p);
	long long ans=0;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		a[i]=0;
		for(int j=0;j<m;j++){
			a[i]=(a[i]<<1)|(s[j]-'0');
		}
	}
	for(int t=0;t<20;t++){
		int x=((rand()<<15)+rand())%n;
		for(long long cur=a[x];cur!=0;cur=((cur-1)&a[x])){
			key.push_back(cur);
		}
	}
	sort(key.begin(),key.end(),cmp());
	key.resize(unique(key.begin(),key.end())-key.begin());
	val.resize(key.size());
	for(int t=0;t<500;t++){
		int x=((rand()<<15)+rand())%n;
		for(long long cur=a[x];cur!=0;cur=((cur-1)&a[x])){
			int id=lower_bound(key.begin(),key.end(),cur,cmp())-key.begin();
			if(id<key.size() && key[id]==cur) val[id]++;
		}
	}
	for(int j=0;j<key.size();j++){
		if(val[j]<200) continue;
		int c=0;
		for(int i=0;i<n;i++){
			if( (a[i]&key[j]) == key[j]) c++;
		}
		if(c>=((n+1)/2)){
			ans=key[j];
			break;
		}
	}
	for(int i=0;i<m;i++){
		s[i]='0'+(ans&1);
		ans>>=1;
	}
	reverse(s,s+m);
	s[m]=0;
	puts(s);
	return 0;
}