Program arsijo;
Var x, y, a, b, i, j, ans, c, d: longint;
Begin
    Read(x, y, a, b);
    while a mod x <> 0 do
        inc(a);
    c := x;
    d := y;
    while (c <> 0) and (d <> 0) do
        if c > d then c := c mod d else d := d mod c;
    c := (x * y) div (c + d);
    WriteLn( (b div c) - ( (a - 1) div c) );
End.