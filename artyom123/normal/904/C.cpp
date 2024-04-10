#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(26);
    int answer = 0;
    bool flag = 0;
    for ( int i = 0; i < n; i++) {

            

        int b = 0;
        for ( int j = 0; j < 26; j++) {
            if ( a[j] == 0) {
                b += 1;
                if ( b > 1) {
                    break;
                }
            }
        }
        if ( b == 1) {
            flag = true;
        }
        string s;
        cin >> s;
        if ( flag == true && (s == "!" || (s == "?" && i < n - 1))) {
            answer += 1;
        }
        string w;
        cin >> w;
        if ( s == "."){

            for ( int j = 0; j < w.size(); j++) {
                a[w[j] - 'a'] = 1;
            }
        }
        else if ( s == "!"){
            int now = 0;
            sort(w.begin(), w.end());

            for ( int j = 0; j < 26; j++) {
                    if ( j != w[now] - 'a') {
                        a[j] = 1;
                    }
                    else {
                        char last = w[now];
                        now += 1;
                        while ( now < w.size() - 1 && w[now] == last) {
                            now += 1;
                        }

                    }

        }
    }
    else {
        a[w[0] - 'a'] = 1;
    }
    }
cout << answer;

    return 0;
}