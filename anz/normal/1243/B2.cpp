 
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
int k; cin>>k;
while(k--)
{
int n;
string a,b;
cin>>n;
cin>>a>>b;
int cnt[26]={0,};
for(int i=0;i<n;i++) cnt[a[i]-'a']++,cnt[b[i]-'a']++;
 
bool flag = true;
for(int i=0;i<26;i++) if(cnt[i]%2) flag=false;
if(!flag) {cout<<"no\n";continue;}
cout <<"yes\n";
vector<pair<int,int> > ans;
for(int i=0;i<n;i++)
{
if(a[i]==b[i]) continue;
bool flag=false;
for(int j=i+1;j<n;j++)
if(a[i]==a[j]){flag=true;ans.push_back({j,i});swap(b[i],a[j]);break;}
 
if(flag) continue;
for(int j=i+1;j<n;j++)
if(a[i]==b[j])
{ans.push_back({i+1,j});ans.push_back({i+1,i});swap(a[i+1],b[j]);swap(a[i+1],b[i]);break;}
}
cout<<ans.size()<<'\n';
for(auto it:ans) cout<<it.first+1<<' '<<it.second+1<<'\n';
}
}