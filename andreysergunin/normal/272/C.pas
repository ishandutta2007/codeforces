var a:array[1..100000] of int64;
    i:longint;
    m,n,w,h:int64;
begin
read (n);
for i:=1 to n do read (a[i]);
read (m);
for i:=1 to m do
        begin
         read (w,h);
         if a[1]>=a[w] then
                begin
                 writeln (a[1]);
                 a[1]:=a[1]+h;
                 a[w]:=a[1];
                end
             else
                begin
                 writeln (a[w]);
                 a[w]:=a[w]+h;
                 a[1]:=a[w];
                end
        end;
end.