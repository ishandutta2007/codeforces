Program arsijo;
Var a, b, c, z, i, n, l, min, minI, j: longint;
        ar, x, y: array [1..3000] of longint;
Begin
        Read(n);
        for i:=1 to n do
            Read(ar[i]);
        l := 0;
        for i:=1 to (n-1) do
        begin
                min := ar[i];
                minI := i;
                for j:=i+1 to n do
                        if ar[j] < min then
                        begin
                            min := ar[j];
                            minI := j;
                        end;
                if minI <> i then
                begin
                    inc(l);
                    x[l] := i;
                    y[l] := minI;
                    b := ar[i];
                    ar[i] := ar[minI];
                    ar[minI] := b;
                end;
        end;
        WriteLn(l);
        for i:=1 to l do
                WriteLn(x[i]-1, ' ', y[i]-1);
End.