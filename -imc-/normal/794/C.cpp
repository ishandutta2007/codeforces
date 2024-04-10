#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string fs, ss;
    cin >> fs >> ss;
    
    int n = fs.size();
    
    sort(all(fs));
    sort(all(ss));
    reverse(all(ss));
    fs.resize((n + 1) / 2);
    ss.resize(n / 2);
    reverse(all(ss));
    
    int l = 0;
    int r = ss.size() - 1;
    int lptr = fs.size() - 1;
    int rptr = 0;
    
    string answer = "";
    string suf = "";
    
    for (int i = 0; i < n; i++)
    {
        if (l > lptr)
            answer += ss[r--];
        else if (r < rptr)
            answer += fs[l++];
        else
        {
            if (i % 2 == 0)
            {
                if (fs[l] < ss[r])
                {
                    answer += fs[l];
                    l++;
                }
                else
                {
                    // droch
                    suf += fs[lptr];
                    lptr--;
                }
            }
            else
            {
                if (fs[l] < ss[r])
                {
                    answer += ss[r];
                    r--;
                }
                else
                {
                    // droch
                    suf += ss[rptr];
                    rptr++;
                }
            }
        }
    }
    
    reverse(all(suf));
    cout << answer + suf << endl;
    
    return 0;
}