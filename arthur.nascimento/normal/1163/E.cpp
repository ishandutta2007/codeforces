#include <bits/stdc++.h>
#define pb push_back
#define maxn 200200
using namespace std;

int v[maxn];

vector<int> base(vector<int> v){
	
	int n = v.size();
	vector<int> r;
	vector<int> esc;
	
	for(int i=0;i<n;i++){
		int u = v[i];
		for(int j=0;j<esc.size();j++)
			if((u^esc[j]) < u)
				u ^= esc[j];
		if(u == 0)
			continue;
		r.pb(v[i]);
		esc.pb(u);
		int pos = esc.size() - 1;
		while(pos > 0 && esc[pos] > esc[pos-1]){
			swap(esc[pos], esc[pos-1]);
			pos--;
		}
	}
	return r;
}

vector<int> go(int x){
	vector<int> r;
	if(x == 0){
		r.pb(0);
		return r;
	}
	vector<int> u = go(x-1);
	r = u;
	for(int i=u.size()-1;i>=0;i--)
		r.pb(u[i]^(1<<(x-1)));
	return r;
}

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	for(int x=20;x>=0;x--){
		
		vector<int> b;
		for(int i=0;i<n;i++)
			if(v[i] < (1<<x))
				b.pb(v[i]);
		
		b = base(b);
		
		if(b.size() < x)
			continue;
		
		printf("%d\n",x);
		
		vector<int> path = go(x);
		
		for(int i=0;i<path.size();i++){
			
			int num = 0;
			for(int j=0;j<x;j++)
				if(path[i] & (1<<j))
					num ^= b[j];
					
			printf("%d ",num);
		
		}
		
		return 0;
	
	}
}