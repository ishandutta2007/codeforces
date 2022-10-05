Program CodF_405VK_A;
var  nal:boolean;
     i,a,b,o:byte;
     ma,mb:array[0..100]of int64;

begin
read(a);
read(b);
ma[0]:=a;
mb[0]:=b;
for i:=1 to 100 do
  begin
    ma[i]:=ma[i-1]*3;
    mb[i]:=mb[i-1]*2;
  end;

nal:=false;
for i:=1 to 100 do
  begin
    if (ma[i]>mb[i]) and (nal=false) then
      begin
        o:=i;
        nal:=true;
      end;
  end;

write(o);
end.