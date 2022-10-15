Program arsijo;
Var n, i, l1, l2, l3: longint;
        ar, a1, a2, a3: array [1..100] of longint;
        bol: array [-1000..1000] of boolean;

Begin
        Read(n);
        for i:=-1000 to 1000 do
                bol[i] := false;
        for i:=1 to n do
                Read(ar[i]);
        l1 := 0;
        l2 := 0;
        l3 := 0;
        for i:=1 to n do
                if ar[i] < 0 then
                begin
                    inc(l1);
                    a1[l1] := ar[i];
                end else if ar[i] > 0 then
                begin
                    inc(l2);
                    a2[l2] := ar[i];
                end else
                begin
                        inc(l3);
                        a3[l3] := 0;
                end;
        if l2 = 0 then
        begin
            l2 := 2;
            a2[1] := a1[l1];
            a2[2] := a1[l1-1];
            dec(l1, 2);
        end;
        if l1 mod 2 = 0 then
        begin
            inc(l3);
            a3[l3] := a1[l1];
            dec(l1);
        end;
        Write(l1);
        for i:=1 to l1 do
                Write(' ', a1[i]);
        WriteLn;
        Write(l2);
        for i:=1 to l2 do
                Write(' ', a2[i]);
        WriteLn;
        Write(l3);
        for i:=1 to l3 do
                Write(' ', a3[i]);
End.