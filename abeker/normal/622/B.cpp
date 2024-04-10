#include <cstdio>
using namespace std;

int main() {
    int hh, mm, a;
    scanf("%d:%d%d", &hh, &mm, &a);
    int t = (hh * 60 + mm + a) % 1440;
    printf("%02d:%02d\n", t / 60, t % 60); 
    return 0;
}