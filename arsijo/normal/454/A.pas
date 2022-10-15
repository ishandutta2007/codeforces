Program arsijo;
Var n, i, j: longint;
Begin
        Read(n);
        for i:=1 to (n div 2) do
        begin
                for j:=1 to ((n div 2) + 1 - i) do
                        Write('*');
                for j:=1 to ((i * 2) - 1) do
                        Write('D');
                for j:=1 to ((n div 2) + 1 - i) do
                        Write('*');
                WriteLn;
        end;
        for i:=1 to n do
                Write('D');
        writeln;
        for i:=(n div 2) downto 1 do
        begin
                for j:=1 to ((n div 2) + 1 - i) do
                        Write('*');
                for j:=1 to ((i * 2) - 1) do
                        Write('D');
                for j:=1 to ((n div 2) + 1 - i) do
                        Write('*');
                WriteLn;
        end;
End.