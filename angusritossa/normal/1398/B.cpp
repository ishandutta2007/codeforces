/*
 For each test case, make a vector of all the lengths of 1s, and sort (in descending order)
 011011110111
 [2, 4, 3]
 [4, 3, 2]
 add the 0th, 2nd, 4th, etc index
*/
#include <cstdio>
#include <vector>
#include <algorithm> // sort, reverse
#include <cstring>
using namespace std;
#define MAXN 110
int t;
char str[MAXN];
int main() {
    scanf("%d", &t);
    for (int CASE = 0; CASE < t; CASE++) {
        scanf(" %s", str);
        int n = strlen(str);
        vector<int> lengths;
        int num_1s = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == '1') {
                num_1s++;
            } 
            if (num_1s != 0 && (str[i] == '0' || i == n-1)) {
                lengths.push_back(num_1s);
                num_1s = 0;
            }
        }
        sort(lengths.begin(), lengths.end());
        reverse(lengths.begin(), lengths.end());
        int ans = 0;
        // add every second length to the answer
        for (int i = 0; i < (int)lengths.size(); i += 2) {
            ans += lengths[i];
        }
        printf("%d\n", ans);
    }
}