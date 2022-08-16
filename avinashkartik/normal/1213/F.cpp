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
	
	cin>>n>>k;
	for(int i = 0 ;i<n; i++){
		cin>>a[i];
		m1[a[i]]=i;
	}
	for(int i = 0 ;i<n; i++){
		cin>>b[i];
		m2[b[i]]=i;
	}
	for(int i = 0 ;i<n; i++){
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	long long int ch[200001]={};
	
	for(int i = 0 ;i<n; i++){
		//cout<<a[i]<<" "<<::max1<<" "<<visited[a[i]]<<"\n";
		if(!visited[b[i]]){
			if(i < ::max1) ::count--;
			::count++;
			//ch[i] = 1;
			dfs(b[i]);
		}
	}

	for(int i = 0 ;i<200001; i++){visited[i] = 0;}

	for(int i = 0 ;i<n; i++){
		//cout<<a[i]<<" "<<::max2<<" "<<visited[a[i]]<<"\n";
		if(!visited[a[i]]){
			//cout<<::count2<<endl;
			if(i < ::max2) ::count2--;
			::count2++;
			//cout<<::count2<<"   ";
			dfs1(a[i]);
		}
	}

	//cout<<::count<<::count2;
	if((::count != ::count2 || ::count< k) && k != 1)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		int c = 1;
		for(int i = 1;i<=n;i++){
			//cout<<ch[i]<<" ";
			if(visited[i] < k)
				ans[i] = char(visited[i] - 1) + 'a';
			else
				ans[i] = 'z';
		}
		for(int i = 1;i<=n;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
}