#include <bits/stdc++.h>

using namespace std;

int query(int ra,int ca,int rb,int cb)
{
    printf("? %d %d %d %d\n",ra,ca,rb,cb);
    fflush(stdout);
    char c[4];
    scanf("%s",c);
    return (c[0]=='Y');
}

int main()
{
	int n;
	scanf("%d",&n);
	int r=1,c=n;
    for(int o=n;o>=1;o--)
    {
        int i=n+1-o;
        if(query(1,1,o,i)&&query(o,i,n,n))
        {
            r=o;
            c=i;
            break;
        }
    }
    vector<char> a,b;
    int o=1,i=1;
    while(o!=r||i!=c)
    {
        if(query(o+1,i,n,n))
        {
            o++;
            a.push_back('D');
        }
        else
        {
            i++;
            a.push_back('R');
        }
    }
    o=i=n;
    while(o!=r||i!=c)
    {
        if(query(1,1,o,i-1))
        {
            i--;
            b.push_back('R');
        }
        else
        {
            o--;
            b.push_back('D');
        }
    }
    reverse(b.begin(),b.end());
    printf("! ");
    for(char t:a) printf("%c",t);
    for(char t:b) printf("%c",t);
    printf("\n");
    fflush(stdout);
	return 0;
}