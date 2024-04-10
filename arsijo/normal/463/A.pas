Var a, p, q, max, n, s, i, x, y: longint;
    b: boolean;
Begin
    Read(n, s);
    max := -1;
    for i:=1 to n do
    begin
        Read(x, y);
        if x < s then
        begin
            if (max = -1) then max := 0;
            if (y <> 0) and ( (100-y) > max ) then max := 100 - y;
        end else if (max = -1) and (x = s) and (y = 0) then max := 0;
    end;
    WriteLn(max);
End.
































{b := false;
    max := 0;
    for i:=1 to n do
    begin
        Read(x, y);
        if x <= s then
        begin
            b := true;
            if (x <> s) and (y > 0) and ((100 - y) > max) then max := (100 - y);
        end;
    end;
    if max <> 0 then WriteLn(max) else if b then WriteLn(0) else WriteLn(-1);}