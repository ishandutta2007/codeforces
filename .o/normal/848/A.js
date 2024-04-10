var l1 = readline().split(' ');
var k = +l1[0];

if(k == 0) {
    print("a");
}else {
    var ans = "";
    function nC2 (n) {
        return n*(n-1)/2;
    }
    for(var rep = 0; k > 0; rep++) {
        var low = 0, high = 1000, cnt = 0;
        while(low <= high) {
            var mid = (low + high) >> 1;
            if(nC2(mid) <= k) {
                cnt = mid;
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        k -= nC2(cnt);
        ans += String.fromCharCode(97 + rep).repeat(cnt);
    }
    print(ans);
}