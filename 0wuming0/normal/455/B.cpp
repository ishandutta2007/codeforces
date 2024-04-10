#include"bits/stdc++.h"
using namespace std;
struct treenode
{
    treenode* pr;
    treenode* next[26];
    int st;
};
void creat(treenode &root,char s[])
{
    treenode *now=&root;
    for(int i=0;s[i];i++)
    {
        if(now->next[s[i]-'a'])
        {
            now=now->next[s[i]-'a'];
        }
        else
        {
            now->next[s[i]-'a']=new treenode;
            now->next[s[i]-'a']->pr=now;//cout<<"ok"<<endl;
            for(int j=0;j<26;j++)now->next[s[i]-'a']->next[j]=NULL;
            now=now->next[s[i]-'a'];
        }
    }
}
int solve(treenode *now)
{
    if(now==0)return 0;
    int a[5]={0};
    for(int i=0;i<26;i++)
    {
        int t=solve(now->next[i]);
        if(t)
        {
            if(t==-2)a[0]=1;
            else if(t==-1)a[1]=1;
            else if(t==1)a[2]=1;
            else if(t==2)a[3]=1;
        }
    }
    if(a[0])now->st=2;
    else if(a[1]>0&&a[2]>0)now->st=2;
    else if(a[1])now->st=1;
    else if(a[2])now->st=-1;
    else if(a[3])now->st=-2;
    else now->st=-1;
    return now->st;
}
char s[100005];
int main()
{
    int n;
    int k;
    treenode root={0};root.pr=0;
    for(int i=0;i<26;i++)root.next[i]=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        creat(root,s);
    }
    int t=solve(&root);//cout<<solve((root.next[0])->next[1])<<endl;
    if(t==-2)cout<<"Second"<<endl;
    else if(t==2)cout<<"First"<<endl;
    else if(t==-1)cout<<"Second"<<endl;
    else
    {
        if(k%2)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}
/*
2 2
ab
a
*/