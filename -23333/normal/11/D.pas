type
  re=record
    a,b,c:int64;
end;
var
  i,j:longint;
  n,m,l,u,v,ans,c,d,x:int64;
  a:array[1..100000]of re;
  head:array[1..100000]of int64;
  ff:Array[1..1 shl 19,1..19]of int64;
procedure arr(x,y:longint);
begin
  inc(l);
  a[l].a:=head[x];
  a[l].b:=y;
  head[x]:=l;
end;
begin
  readln(n,m);
  for i:=1 to m do
  begin
    read(c,d); arr(c,d); arr(d,c);
  end;
  for i:=1 to n do
    ff[1<<(i-1),i]:=1;
  for i:=1 to (1<<n)-1 do
  begin
    for j:=1 to n do
      if i and (1<<(j-1))=1<<(j-1) then
      begin
        x:=j; break;
      end;
    for j:=1 to n do
      if (i and (1<<(j-1))=1<<(j-1)) then
      begin
        u:=head[j];
        while u<>0 do
        begin
          v:=a[u].b;
          if (v>=x) then
          begin
            if v=x then ans:=ans+ff[i,j]
            else {if i and 1<<(v-1)=0  then} inc(ff[i xor (1<<(v-1)),v],ff[i,j]);
          end;
          u:=a[u].a;
        end;
      end;
  end;
  writeln((ans-m) div 2);
end.