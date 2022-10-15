Program arsijo;
uses math;
Var n, i, pos, count, e: longint;
        ar: array[1..300] of longint;

Begin
        Read(n);
        for i:=1 to n do
                Read(ar[i]);
        for i:=1 to (n div 2) do
        begin
            while (ar[i*2-1] + ar[i*2]) > 0 do
            begin
                if ar[i*2-1] > 0 then
                        Write('P');
                Write('R');
                if ar[i*2] > 0 then
                        Write('P');
                Write('L');
                ar[i*2-1] := max(ar[i*2-1]-1, 0);
                ar[i*2] := max(ar[i*2]-1, 0);
                //WriteLn(ar[i*2-1], ' ', ar[i*2]);
            end;
            if i <> (n div 2) then
                Write('RR');
        end;
        if ((n mod 2) = 1) and (ar[n] <> 0) then
        begin
                Write('RR');
                for i:=1 to ar[n] do
                        Write('PLR');
        end;

End.