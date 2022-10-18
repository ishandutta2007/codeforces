#ifdef __APPLE__
# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_map>
# include <unordered_set>
# include <thread>
#else
# include <bits/stdc++.h>
#endif

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int max_n = 2e6+10, inf = 1000111222;
const int md=1e9+7;

int dp[max_n];

int get_ans(string s)
{
    if (s=="1"){
        return 1;
    }
    s.pop_back();

    vector<int> kek;
    for (auto i:s){
        if (i=='1'){
            kek.pb(0);
        }
        else{
            kek.back()++;
        }
    }

//    dp[len(kek)]=1;
//    for (int i=len(kek)-1;i>=0;i--){
//        dp[i]=(dp[i+1]+1);
//        if (dp[i]>=md){
//            dp[i]-=md;
//        }
//        int last=0;
//        for (int j=i;j<len(kek);j++){
//            while (last<kek[j]){
//                dp[i]=(dp[i]+dp[j+1]);
//                if (dp[i]>=md){
//                    dp[i]-=md;
//                }
//
//                last++;
//            }
//        }
//        cout<<"dp["<<i<<"] :: "<<dp[i]<<"\n";
//    }
//    memset(dp,0,sizeof(dp));

    dp[len(kek)]=1;
    vector<int> poses;
    int sum_of_poses=0;
    for (int i=len(kek)-1;i>=0;i--){
        dp[i]=(dp[i+1]+1);
        if (dp[i]>=md){
            dp[i]-=md;
        }
        while (!poses.empty() && kek[poses.back()]<=kek[i]){
            if (len(poses)>=2){
                sum_of_poses-=1ll*(kek[poses[len(poses)-2]]-kek[poses[len(poses)-1]])*dp[poses[len(poses)-2]+1]%md;
                if (sum_of_poses<0){
                    sum_of_poses+=md;
                }
            }
            poses.pop_back();
        }

        poses.pb(i);
        if (len(poses)>=2){
            sum_of_poses+=1ll*(kek[poses[len(poses)-2]]-kek[poses[len(poses)-1]])*dp[poses[len(poses)-2]+1]%md;
            if (sum_of_poses>=md){
                sum_of_poses-=md;
            }
        }
        dp[i]=(dp[i]+sum_of_poses);
        if (dp[i]>=md){
            dp[i]-=md;
        }
        dp[i]=(dp[i]+1ll*kek[i]*dp[i+1]%md);
        if (dp[i]>=md){
            dp[i]-=md;
        }
//        cout<<"dp["<<i<<"] :: "<<dp[i]<<"\n";
    }
    return dp[0];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin>>s;
    if (*max_element(all(s))=='0'){
        cout<<len(s)<<"\n";
        return 0;
    }
    int kf1=1;
    while (s.back()=='0'){
        kf1++;
        s.pop_back();
    }

    reverse(all(s));
    int kf2=1;
    while (s.back()=='0'){
        kf2++;
        s.pop_back();
    }
    reverse(all(s));

    int ans=get_ans(s);

    cout<<(1ll*kf1*ans%md)*1ll*kf2%md<<"\n";
}