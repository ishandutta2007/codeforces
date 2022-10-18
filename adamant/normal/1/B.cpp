#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char tmp[1000001][7];
int len[1000001];

void add1(char *c1, char *c)
{
    int i;
    for(i=0; c1[i]=='Z'; i++) c[i]='A';
    if (!c1[i]) c[i]='A';
    else
    {
        c[i]=c1[i]+1;
        for(i++; c1[i]; i++) c[i]=c1[i]; 
    }
}

int bin_search(char *c)
{
    int p, q, i, l, tmp1;
    l=strlen(c);
    for(p=1, q=1000000; p<=q;)
    {
        i=(p+q)>>1;
        if (l<len[i]) q=i-1;
        else if (l>len[i]) p=i+1;
        else 
        {
            tmp1=strcmp(c, tmp[i]);
            if (tmp1<0) q=i-1;
            else if (tmp1>0) p=i+1;
            else return i;
        }
    }
    return i;
}

int get_hsh(char *c)
{
    int ans=0;
    for(int i=0; c[i]; i++)
        ans=ans*27+c[i]-'A'+1;
    return ans;
}

int main()
{   
   
    int n, i, j, k, l, f, v1, v2, ll;
    string st;
    char s[25], s1[25];
    len[1]=1; tmp[1][0]='A';
    for(i=2; i<=1000000; i++)
    {
        add1(tmp[i-1], tmp[i]);
        len[i]=strlen(tmp[i]);  
    }
    for(i=1; i<=1000000; i++)
        reverse(tmp[i], tmp[i]+len[i]); 
    scanf("%d", &n);
    for(j=0; j<n; j++)
    {
        scanf("%s", &s);
        l=strlen(s);
        f=0;
        if (s[0]=='R' && s[1]>='1' && s[1]<='9')
        {
            for(i=2; i<l; i++)
                if (s[i]=='C') {f=1; break;}
            if (f)
            {
                for(v1=0, k=1; k<i; k++)
                    v1=v1*10+s[k]-'0';
                for(v2=0, k=i+1; k<l; k++)
                    v2=v2*10+s[k]-'0';
                printf("%s%d\n", tmp[v2], v1);
                continue;
            }
        }
        for(i=0; s[i]>='A'; i++)
            s1[i]=s[i];
        s1[i]=0;
        v1=bin_search(s1);
        for(v2=0; i<l; i++)
            v2=v2*10+s[i]-'0';
        printf("R%dC%d\n", v2, v1);
    }
    
}