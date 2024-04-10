Program arsijo;
Uses math;
Var n, i, m, j, a, b, ans: longint;
        x, y: array [0..101] of longint;
Begin
    Read(n);
    ans := 0;
    for i:=1 to n do
    begin
        Read(a);
        inc(x[a]);
    end;
    Read(m);
    for i:=1 to m do
    begin
        Read(a);
        inc(y[a]);
    end;
    a := 0;
    for i:=1 to 100 do
    begin
        if x[i] = 0 then continue;
        if y[i-1] <> 0 then
        begin
                b := min(x[i], y[i-1]);
                ans := ans + b;
                dec(x[i], b);
                dec(y[i-1], b);
        end;
        if x[i] <= 0 then continue;
        if y[i] <> 0 then
        begin
                b := min(x[i], y[i]);
                ans := ans + b;
                dec(x[i], b);
                dec(y[i], b);
        end;
        if x[i] <= 0 then continue;
        if y[i+1] <> 0 then
        begin
                b := min(x[i], y[i+1]);
                ans := ans + b;
                dec(x[i], b);
                dec(y[i+1], b);
        end;
    end;
    WriteLn(ans);
End.