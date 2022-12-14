var l = readline().split(' ');
var m = +l[0];
var a = readline().split(' ').map(function(v){return +v;});
var b = readline().split(' ').map(function(v){return +v;});

var bp = new Array(m);
for(var i = 0; i < m; i++) {
    bp[i] = [b[i], i];
}
function sortBP(p,q) {
    return p[0] - q[0];
}
bp.sort(sortBP);

function sortNumber(p,q) {
    return p - q;
}
a.sort(sortNumber);
var ans = new Array(m);
for(var i = 0; i < m; i++) {
    ans[bp[i][1]] = a[m-i-1];
}
print(ans.join(" "));