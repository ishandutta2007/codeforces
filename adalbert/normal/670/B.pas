var n,k,tep:int64;
i:longint;
a:array[1..1000000] of int64;
begin
{assign(input,'gold.in'); reset(input);
assign(output,'gold.out'); rewrite(output); }
read(n,k);
for i:=1 to n do read(a[i]);
tep:=1;
while k>tep do
    begin
    k:=k-tep;
    inc(tep);
    {writeln(k);}
    end;
writeln(a[k]);
end.