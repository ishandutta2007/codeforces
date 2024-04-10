#include <map>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    map <string, string> Par;
    string A, B, C; int q; scanf("%d", &q);

    while (q--) {
        cin >> A >> B;
        if (!Par.count(A)) Par[B] = A;
        else {
            C = Par[A];
            Par.erase(A);
            Par[B] = C;
        }
    }

    printf("%d\n", Par.size());
    for (map <string, string> :: iterator it = Par.begin(); it != Par.end(); ++it)
        cout << (it -> second) << " " << (it -> first) << endl;
	return 0;
}