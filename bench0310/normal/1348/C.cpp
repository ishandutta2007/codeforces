#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    char s[100005];
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        vector<int> cnt(26,0);
        for(int i=0;i<n;i++) cnt[s[i]-'a']++;
        int idx=0;
        vector<string> v(k);
        auto mv=[&]()->bool
        {
            while(idx<26&&cnt[idx]==0) idx++;
            return (idx<26);
        };
        mv();
        if(cnt[idx]<k)
        {
            for(int i=0;i<k;i++)
            {
                v[i]+=(idx+'a');
                cnt[idx]--;
                mv();
            }
            printf("%s\n",v[k-1].c_str());
            continue;
        }
        for(int i=0;i<k;i++)
        {
            v[i]+=(idx+'a');
            cnt[idx]--;
            n--;
        }
        mv();
        int z=0;
        for(int i=idx;i<26;i++) z+=(cnt[i]>0);
        if(z==1)
        {
            while(cnt[idx]>0)
            {
                for(int i=0;i<k;i++)
                {
                    v[i]+=(idx+'a');
                    cnt[idx]--;
                    if(cnt[idx]==0) break;
                }
            }
        }
        else
        {
            while(mv())
            {
                v[0]+=(idx+'a');
                cnt[idx]--;
            }
        }
        printf("%s\n",v[0].c_str());
    }
    return 0;
}