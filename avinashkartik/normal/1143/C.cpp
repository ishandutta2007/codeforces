#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

long long int count = 0;
int visited[200001]={};

vector<int> v[200001];
long long int max1 = -1;
long long int max2 = -1;
long long int count2 = 0;
unordered_map<long long int ,long long int>m1,m2;

void dfs(int x){
	for(auto i: v[x]){
		if(!visited[i]){
			//cout<<i<<" "<<endl;
			if(max(m1[i],m2[i]) > ::max1)
				::max1 = max(m1[i],m2[i]);
			visited[i] = ::count;
			dfs(i);
		}
	}
}

void dfs1(int x){
	for(auto i: v[x]){
		if(!visited[i]){
			//cout<<i<<" "<<endl;
			if(max(m1[i],m2[i]) > ::max2)
				::max2 = max(m1[i],m2[i]);
			visited[i] = ::count2;
			dfs1(i);
		}
	}
}

char ans[200001];
char val = 'a';

int main(){
	int n,k,u,v1,a[200001],b[200001];
	long long int ch[200001]={};
	cin>>n;

	for(int i = 1 ;i<=n; i++){
		cin>>u>>v1;
		if(u!= -1)
			v[u].push_back(i);
		ch[i] = v1;
	}

	int flag;
	for(int i = 1 ;i<=n; i++){
		flag = 0;
		for(auto x : v[i]){
			if(ch[x] == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0 && ch[i] == 1){
			cout<<i<<" ";
			::count++;
		}
	}
	if(::count == 0) cout<<"-1";
}