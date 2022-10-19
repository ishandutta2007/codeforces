#include"bits/stdc++.h"
using namespace std;
char s[100005];
char ans[100005];
int save[1005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        scanf("%s",s);
        for(int i='a';i<='z';i++)save[i]=0;
        if(n%k!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        int rz=0;
        //for(int i=0;i<n;i++)
        int num=n/k;
        int last=0;
        int i;
        for(i=0;i<n;i++)
        {//cout<<"<<<"<<i<<" "<<num<<endl;
            be:;
            if(save[s[i]]==0)
            {//cout<<">>>"<<num<<endl;
                if(num>0)
                {
                    num--;
                    save[s[i]]+=k;
                    if(s[i]!='z')last=i;
                    goto be;
                }
                else
                {
                    for(int j=s[i]+1;j<='z';j++)if(save[j])
                    {
                        last=i;
                        goto aaa;
                    }goto aaa;
                }
            }
            else
            {
                if(s[i]!='z'&&num>0)last=i;
                    for(int j=s[i]+1;j<='z';j++)if(save[j])
                    {
                        last=i;
                        goto outt;
                    }
                    outt:;
                save[s[i]]--;
            }
        }//cout<<"ok"<<endl;
        {
            printf("%s\n",s);
            continue;
        }
        aaa:;
        num=n/k;//cout<<"<<<<"<<last<<endl;
        for(int i='a';i<='z';i++)save[i]=0;
        for(i=0;i<last;i++)
        {
            if(save[s[i]]==0)
            {
                num--;
                save[s[i]]+=k;
                i--;
            }
            else
            {
                save[s[i]]--;
            }
        }
        if(num>0&&save[s[last]+1]!=0)
        {
            save['a']+=num*k;
        }
        else if(num>0&&save[s[last]+1]==0)
        {
            save['a']+=(num-1)*k;
            if(s[last]=='z')return 1;
            save[s[last]+1]+=k;
        }//cout<<num<<" "<<save['a']<<" "<<save['b']<<" "<<save['c']<<endl;
        while(save[s[last]+1]==0)s[last]++;//cout<<s[last]<<endl;
        s[last]++;
        save[s[last]]--;
        for(i=last+1;i<n;i++)
        {
            for(int j='a';j<='z';j++)
            {
                if(save[j])
                {
                    save[j]--;
                    s[i]=j;
                    break;
                }
            }
        }
        printf("%s\n",s);
    }
    return 0;
}
/*
4
4 2
abcd
3 1
abc
4 3
aaaa
9 3
abaabaaaa

4
4 2
zzzz
4 2
zzaa
4 2
bzza
4 2
azzb
*/