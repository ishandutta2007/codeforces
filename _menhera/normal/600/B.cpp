#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for(int i=0; i<N; ++i) cin >> A[i];
    for(int i=0; i<M; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    for(int v: B)
        cout << upper_bound(A.begin(), A.end(), v) - A.begin() << ' ';
    cout << endl;
}