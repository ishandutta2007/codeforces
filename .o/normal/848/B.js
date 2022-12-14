var l1 = readline().split(' ');
var n = +l1[0];
var w = +l1[1];
var h = +l1[2];

var src = new Array(n);
var dest = new Array(n);
for(var i = 0; i < n; i++) {
    var line = readline().split(' ');
    var p = +line[1], t = +line[2];
    var x1, y1, x2, y2;
    if(line[0] == '1') { // vertical
        x1 = p; y1 = -t;
        x2 = p; y2 = +h;
    }else {
        x1 = -t; y1 = p;
        x2 = +w; y2 = p;
    }
    src[i] = ([x1+y1, x1, y1, i]);
    dest[i] = ([x1+y1, x2, y2, i]);
}

function comp (p, q) {
    return p[0] != q[0] ? p[0] - q[0] : p[1] != q[1] ? p[1] - q[1] : p[2] != q[2] ? q[2] - p[2] : p[3] - q[3];
    
}

src.sort(comp);
dest.sort(comp);

var ans = new Array(n);
for(var i = 0; i < n; i++) {
    ans[src[i][3]] = dest[i][1] + " " + dest[i][2];
}
print(ans.join("\n"));