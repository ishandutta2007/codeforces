#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector <int> V;
    for (int i = 0; i < N; i++) {
        V.push_back(1);
        while (V.size() > 1 && V.back() == V[(int)V.size() - 2]) {
            V.pop_back();
            V[(int)V.size() - 1]++;
        }
    }
    
    for (int i = 0; i < V.size(); i++)
        printf("%d ", V[i]);
    puts("");
    return 0;
}