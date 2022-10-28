    #include <bits/stdc++.h>
    using namespace std;
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #define endl "\n"
    #define mod 1000000007
    #define int long long
    #define ll long long
    #define EPS 0.000000001
    #define ld long double
    #define inf 5e18
    #define N 3000
     
     
     
    int32_t main()
    {
        IOS;
        #ifndef ONLINE_JUDGE
        freopen("int.txt","r",stdin);
        freopen("out.txt","w",stdout);
        #endif
        int n,l,k;
        cin >> n >> l >> k;
        string letters;
        cin >> letters;
        multiset<char> s;
        vector<int> freq(26,0);
        for(int i = 0;i < letters.length();i++)
        {
            freq[letters[i] - 'a']++;
        }
        vector<string> ans(n,"");
        int cur = 0;
        for(int i  = 0;i < l;i++)
        {
            for(char p = 'a';p <= 'z';p++)
            {
                int f = 0;
                int total = k - cur;
                for(char g = 'a';g <= p;g++)
                {
                    f += freq[g - 'a'];
                }
                if(f >= total)
                {
                    ans[k - 1] += p;
                    freq[p - 'a']--;
                    for(char g = 'a';g < p and cur < k - 1;g++)
                    {
                        while(freq[g - 'a'] and cur < k - 1)
                        {
                            freq[g - 'a']--;
                            ans[cur] += g;
                            cur++;
                        }
                    }
                    int j = cur;
                    for(char g = p;j < k - 1;j++)
                    {
                        freq[g - 'a']--;
                        ans[j] += g;
                       
                       

                    }
                    break;
                }
            }
        }
        for(int i = 0;i < 26;i++)
        {
            while(freq[i])
            {
                s.insert((char)(97 + i));
                freq[i]--;
            }
        }
        for(int i = 0;i < n;i++)
        {
            while(ans[i].length() < l)
            {
                ans[i] += *s.begin();
                s.erase(s.begin());
            }
        }
        sort(ans.begin(),ans.end());
        for(auto it : ans)
            cout << it << endl;
     
        
        return 0;
     
    }