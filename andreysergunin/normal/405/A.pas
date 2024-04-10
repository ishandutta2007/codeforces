var a,u,v:array[1..1000] of longint;
    n,i,j:longint;
begin
 read (n);
 for i:=1 to n do
        begin
         read (a[i]);
         for j:=1 to a[i] do inc (u[j]);
        end;
 for i:=1 to 100 do
        begin
         for j:=1 to u[i] do inc (v[j]);
        end;
 for i:=n downto 1 do write (v[i],' ');
end.