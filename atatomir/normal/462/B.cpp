#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

long n,k,i;
char s[100005];
long sum[26];
long long ans;

/*ifstream fin("test.in");
#define cin fin*/

int main()
{
    cin >> n >> k;
    cin.getline(s,10);
    cin.getline(s,sizeof(s));
    for(i=0;i<n;i++)
        sum[s[i]-'A']++;

    sort(sum,sum+26);
    for(i=25;i>=0;i--){
        long add = min(k,sum[i]);
        ans += 1LL*add*add;
        k -= add;
        if(k == 0) break;
    }
    cout <<ans;

    return 0;
}