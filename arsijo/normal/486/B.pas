Program arsijo;
var n, m, i, j, a, c: longint;
    b: boolean;
    ar, res: array [1..100] of array [1..100] of longint;
    bol: array [1..100] of array [1..100] of boolean; // isUsed
Begin
    Read(n, m);
    for i:=1 to n do
        for j:=1 to m do
        begin
            Read(ar[i, j]);
            bol[i, j] := false;
            res[i, j] := 0;
        end;
    for i:=1 to n do
        for j:=1 to m do
        begin
            b := false;
            for a:=1 to n do
                if ar[a, j] = 0 then
                begin
                    b := true;
                    break;
                end;
            if b then continue;
            for a:=1 to m do
                if ar[i, a] = 0 then
                begin
                    b := true;
                    break;
                end;
            if b then continue;
            for a :=1 to n do
                bol[a, j] := true;
            for a :=1 to m do
                bol[i, a] := true;
            res[i, j] := 1;
        end;
    for i:=1 to n do
        for j :=1 to m do
        begin
            if (ar[i, j] = 1) and not(bol[i, j]) then
            begin
                WriteLN('NO');
                exit;
            end;
        end;
    WriteLn('YES');
    for i:=1 to n do
    begin
        for j:=1 to m do
            Write(res[i, j], ' ');
        writeln;
    end;
End.