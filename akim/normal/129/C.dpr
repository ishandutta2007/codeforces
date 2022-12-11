var a,b:array[0..9,0..9]of char;
    i,f,g:longint;
begin
 for i:=8 downto 1 do
 begin
  for f:=1 to 8 do
   read(a[i,f]);
  readln;
 end;
 for g:=12 downto 1 do
 begin
  b:=a;
  for i:=1 to 8 do
   for f:=1 to 8 do
    a[i,f]:='.';
  for i:=1 to 8 do
   for f:=1 to 8 do
   begin
    if b[i,f]='M' then 
    begin
     a[i,f]:='M';
     a[i,f+1]:='M';
     a[i,f-1]:='M';
     a[i+1,f]:='M';
     a[i-1,f]:='M';
     a[i+1,f+1]:='M';
     a[i+1,f-1]:='M';
     a[i-1,f+1]:='M';
     a[i-1,f-1]:='M';
    end;
   end;
  for i:=1 to 8 do
   for f:=1 to 8 do
    if b[i,f]='S' then 
    a[i,f]:='S';
  for i:=1 to 8 do
   for f:=1 to 8 do
    if a[i,f]='S' then begin a[i,f]:='.';a[i-1,f]:='S';end;
 end;
 for i:=1 to 8 do
  for f:=1 to 8 do
   if a[i,f]='M' then begin writeln('WIN');halt(0);end;
 writeln('LOSE');
end.