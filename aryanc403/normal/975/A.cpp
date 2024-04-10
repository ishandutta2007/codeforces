//for(auto a: x);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#define fo(i,n)   for(i=0;i<(n);++i)
#define LLI long long int
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MAX 1000002
#define MOD 1000000007

LLI T,n,in,i,m,j;
LLI a[3][1005][26];

bool cmp(LLI b,LLI i,LLI c,LLI j)//<=
{
    for(LLI k=0;k<26;++k)
    {
        if(a[b][i][k]<a[c][j][k])
        {
            return true;
        }
        if(a[b][i][k]>a[c][j][k])
        {
            return false;
        }
    }
    return true;
}

bool equal(LLI b,LLI i,LLI c,LLI j)//==
{
    for(LLI k=0;k<26;++k)
    {
        if(a[b][i][k]!=a[c][j][k])
        {
            return false;
        }
    }
    return true;
}


void merge(LLI l,LLI r1,LLI l2,LLI r)
{
    LLI n=r1-l+1,i;
    LLI m=r-l2+1,j;
    for(i=0;i<n;++i)
    for(j=0;j<26;++j)
    a[1][i][j]=a[0][i+l][j];
    
    for(i=0;i<m;++i)
    for(j=0;j<26;++j)
    a[2][i][j]=a[0][i+l2][j];
    LLI k=l;
    i=0;
    j=0;
    while(i<n&&j<m)
    {
        if(cmp(1,i,2,j))
        {
            //copyb
            for(LLI b=0;b<26;++b)
            {
                a[0][k][b]=a[1][i][b];
            }
            i++;
        }
        else
        {
            //copyc
            for(LLI b=0;b<26;++b)
            {
                a[0][k][b]=a[2][j][b];
            }
            j++;
        }
        k++;
    }
    while(i<n)
    {
            //copyb
            for(LLI b=0;b<26;++b)
            {
                a[0][k][b]=a[1][i][b];
            }
            i++;
        k++;
    }
    
    while(j<m)
    {
            //copyc
            for(LLI b=0;b<26;++b)
            {
                a[0][k][b]=a[2][j][b];
            }
            j++;
        k++;
    }
}
void SORT(LLI l,LLI r)
{
    if(l==r)
        return;
    LLI mid=l+(r-l)/2;
    SORT(l,mid);
    SORT(mid+1,r);
    merge(l,mid,mid+1,r);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    string s;
    for(i=0;i<n;++i)
    {
        cin>>s;
        //cout<<"|"<<s<<"|"<<endl;
        LLI b[26];
        for(j=0;j<26;++j)
            a[0][i][j]=0;
        for(j=0;j<s.size();++j)
            a[0][i][s[j]-'a']=1;
        //cout<<endl;
    }
    
    SORT(0,n-1);
    LLI cnt=0;
    a[0][n][0]=-1;
    for(i=0;i<n;++i)
    {
    	/*printf("|");
    	for(j=0;j<26;++j)
    	{
    		if(a[0][i][j])
    		{
    			printf("%c",'a'+j);
			}
		}
		printf("|\n");*/
        if(equal(0,i,0,i+1)==false)
        {
            cnt++;
            //printf("cnt++ %lldi\n",i);
        }
    }
    cout<<cnt;
    return 0;
}