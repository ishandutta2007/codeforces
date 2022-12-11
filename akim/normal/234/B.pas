var a:array[1..1000,1..2]of longint;
    n,m,i,f,z:longint;
begin
 assign(input,'input.txt');reset(input);
 assign(output,'output.txt');rewrite(output);
 readln(n,m);
 for i:=1 to n do
 begin read(a[i,1]);a[i,2]:=i;end;
 for i:=1 to n-1 do
  for f:=i+1 to n do
   if a[i,1]<a[f,1] then begin
                          z:=a[i,1];
                          a[i,1]:=a[f,1];
                          a[f,1]:=z;
                          z:=a[i,2];
                          a[i,2]:=a[f,2];
                          a[f,2]:=z;
                         end;
 writeln(a[m,1]);
 for i:=1 to m do
  write(a[i,2],' ');
 close(input);close(output);
end.