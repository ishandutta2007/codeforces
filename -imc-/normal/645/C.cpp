#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    k++;
    
    string s;
    cin >> s;
    
    int l = 0, r = 0;
    int m = 0;
    vector<int> places;
    int pl = 0;
    
    int answer = (int)1e9;
    
    while (true)
    {
        while ((int)places.size() - pl < k)
        {
            if (r == n)
                goto breakAll;
            
            if (s[r] == '0')
                places.push_back(r);
            r++;
        }
        
        while (m + 1 < (int)places.size() && max(places.back() - places[m + 1], places[m + 1] - places[pl]) <= max(places.back() - places[m], places[m] - places[pl]))
            m++;
        
        answer = min(answer, max(places.back() - places[m], places[m] - places[pl]));
        
        if (s[l] == '0')
        {
            pl++;
        }
        
        l++;
    }
    
    breakAll:;
    
    printf("%d\n", answer);
    
    return 0;
}