Program arsijo;
uses math;
var n, i, a: longint;
    m, x, y, north, west, south, east: int64;
Begin
    Read(n);
    Read(x, y);
    north := y; south := y;
    west := x; east := x;
    for i:=2 to n do
    begin
        Read(x, y);
        if x < west then west := x;
        if x > east then east := x;
        if y > north then north := y;
        if y < south then south := y;
    end;
    m := max(abs(east - west), abs(north - south) ) ;

    WriteLn(sqr(m));
End.