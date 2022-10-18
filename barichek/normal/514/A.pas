uses math;
var
  a:array[1..10000]of longint;
  s:string;
  i,h,l:longint;
begin
  read(s);
  h:=0;

  if s[1]='9' then write(9)
  else begin
         a[1]:=ord(s[1])-48;
         if a[1]>=5 then a[1]:=9-a[1];
         write(a[1]);
       end;

  for i:=2 to length(s) do
    begin
      a[i]:=ord(s[i])-48;
      if a[i]>=5 then a[i]:=9-a[i];
      write(a[i]);
    end;
end.