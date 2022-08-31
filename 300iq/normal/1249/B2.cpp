#include <bits/stdc++.h>

using namespace std;

int main(){
int q;
cin>>q;
while (q--){
int n;
cin>>n;
vector<int>p(n);
for(int i =0;i<n;i++){
cin>>p[i];
p[i]--;
}
vector<int>ans(n);
for (int i =0;i<n;i++){
if (p[i]!=-1){
int x = i;
int s =0;
vector<int>t;
while (x!=-1){
t.push_back(x);
s++;
int f = x;
x = p[x];
p[f]=-1;
}
for (int a : t) ans[a]=s-1;
}
}
for (int x : ans) cout << x << ' ';
}
}