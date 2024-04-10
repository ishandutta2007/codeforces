Program arsijo;
Var n, i, j, m: longint;
        ar: array [1..100000] of longint;
        bo: boolean;
Begin
        Read(n);
        for i:=1 to n do
                Read(ar[i]);
        bo := true;
        for i:=2 to n do
                if ar[i] < ar[i-1] then
                begin
                    if bo then
                    begin
                        bo := false;
                        if ar[i] > ar[1] then
                        begin
                            WriteLn(-1);
                            exit;
                        end else m := i;
                    end else
                    begin
                        WriteLn(-1);
                        exit;
                    end;
                end;
        if (not(bo)) and (ar[n] > ar[1]) then WriteLn(-1) else
        if m = 0 then WriteLn(0) else
                WriteLn(n - m + 1);
End.