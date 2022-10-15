Program arsijo;
uses math;
Var n, i, b, c: longint;
        x, y: array [1..200000] of longint;
        sum, a: int64;
Begin
        Read(n);
        sum := 0;
        a := 0;
        b := 0;
        c := 0;
        for i:=1 to n do
        begin
            Read(a);
            sum := sum + a;
            if (a > 0) then
            begin
                inc(b);
                x[b] := abs(a);
            end else
            begin
                inc(c);
                y[c] := abs(a);
            end;
        end;
        if sum < 0 then
                WriteLn('second') else
        if sum > 0 then
                WriteLn('first') else
        begin
            {if (b > c) then
                WriteLn('second') else
            if (b < c) then
                WriteLn('first') else
            begin }
                //WriteLn('+');
                for i:=1 to min(b, c) do
                begin
                    //    WriteLN(x[i], ' ', y[i]);
                    if x[i] > y[i] then
                        WriteLn('first') else
                    if x[i] < y[i] then
                        WriteLn('second');
                    if x[i] <> y[i] then exit;
                end;
                //WriteLn('+');
                if b > c then
                        WriteLn('second') else
                if b < c then
                        WriteLn('first') else
                if a < 0 then
                        WriteLn('second') else
                        WriteLn('first');
            //end;
        end;
End.