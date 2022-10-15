Program arsijo;
Var n, k, x1, y1, x2, y2, i: longint;
        sum: extended;
Begin
    Read(n, k, x1, y1);
    sum := 0;
    for i:=2 to n do
    begin
        Read(x2, y2);
        sum := sum + sqrt ( sqr ( x1 - x2 ) + sqr ( y1 - y2 ) );
        //WriteLn( sqr ( x1 - x2 ), ' ', sqr ( y1 - y2 ));
        x1 := x2;
        y1 := y2;
    end;
    sum := sum / 50;
    sum := sum * k;
    WriteLn(sum:0:9);
End.