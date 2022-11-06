#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int main() {
	int ab, ac, bc, abc;
	scanf("%d%d%d%d", &ab, &ac, &bc, &abc);
	if (ab > abc) swap(ab, abc);
	if (bc > abc) swap(bc, abc);
	if (ac > abc) swap(ac, abc);
	printf("%d %d %d", ab + ac - abc, ab + bc - abc, ac + bc - abc);
}