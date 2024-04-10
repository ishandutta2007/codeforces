Program arsijo;
Var n, i, l, r: longint;
        ar: array [1..100000] of longint;
Begin
        Read(n);
        for i:=1 to n do
                Read(ar[i]);
        l := 1;
        r := n;
        while (ar[l+1] > ar[l]) and (l < n) do inc(l);
        if l <> n then
        begin
                while (ar[r-1] < ar[r]) and (r > 1) do dec(r);
               // WriteLn(l, ' ', r);
                if ((ar[r] >= ar[l-1]) or (l = 1)) and ((ar[l] <= ar[r+1]) or (r = n)) then
                begin
                      //  WriteLn('+');
                        for i:=l+1 to r do
                                if ar[i] > ar[i-1] then
                                begin
                                    WriteLn('no');
                                    exit;
                                end;
                        WriteLn('yes');
                        WriteLn(l,' ', r);
                end else WriteLn('no');
        end else
        begin
                WriteLn('yes');
                WriteLn('1 1');
        end;
End.