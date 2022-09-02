#include <bits/stdc++.h>
using namespace std;

int f(char a)
{
    return int(a)-97;
}

char inv (int a)
{
    return char(a+97);
}

int component[26];
bool visited[26] = {0};

int compcount = 0;
int G[26][26] = {0};

void dfs(int v)
{
    visited[v] = true;
    component[v] = compcount;
    for (int i = 0; i<26; i++) if ((G[v][i]==1)&&(!visited[i])) dfs(i);
}



int main() 
{
    int n;
    cin>>n;
    string a;
    string b;
    cin>>a>>b;
    for (int i = 0; i<n; i++) if (a[i]!=b[i]) {G[f(a[i])][f(b[i])] = 1; G[f(b[i])][f(a[i])] = 1;}
    
    for (int i = 0; i<26; i++)
    {
        if (!visited[i]) {compcount++; dfs(i);}
    }
    
    int countt = 0;
        for (int i = 1; i<=compcount; i++)
    {
        int j = 0;
        while (component[j]!=i) j++;
        for (int s = j+1; s<26; s++) if (component[s]==i) countt++;
    }
    cout<<countt<<endl;
    for (int i = 1; i<=compcount; i++)
    {
        int j = 0;
        while (component[j]!=i) j++;
        for (int s = j+1; s<26; s++) if (component[s]==i) cout<<inv(s)<<' '<<inv(j)<<endl;
    }
    
    
    
    
    

}