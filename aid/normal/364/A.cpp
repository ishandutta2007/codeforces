#include <iostream>
#include <string>

using namespace std;

const int SQRTA = 100 * 1000 + 5;
int c[SQRTA];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    int a;
    cin >> a >> s;
    for(size_t i = 0; i < s.length(); i++) {
        int sum = 0;
        for(size_t j = i; j < s.length(); j++) {
            sum += s[j] - '0';
            if(sum * sum <= a)
                c[sum]++;
        }
    }
    long long ans = 0;
    for(size_t i = 0; i < s.length(); i++) {
        int sum = 0;
        for(size_t j = i; j < s.length(); j++) {
            sum += s[j] - '0';
            if(sum * sum > a && !(a % sum))
                ans += 2 * c[a / sum];
            else if(sum * sum == a)
                ans += c[sum];
        }
    }
    cout << ans << '\n';
    return 0;
}